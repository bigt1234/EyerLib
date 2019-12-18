#ifndef	RED_LRU_MAP_H
#define	RED_LRU_MAP_H

#include <mutex>
#include <map>

template <typename T>
class RedLruData
{
public:
    int hot = 0;
    T t;

    ~RedLruData(){
        delete t;
    }
};

template <typename K, typename V>
class RedLruMap
{
private:
    std::mutex mut;
    std::map<K, RedLruData<V> *> mapSet;

    int maxSize = 0;
public:
    RedLruMap(int maxSize = 10);
    ~RedLruMap();

    int LruRemove();
    int LruRemoveHotless();

    int Get(const K & k, V & v);
    int Put(const K & k, V & v);

    int Size();
};

template <typename K, typename V>
RedLruMap<K, V>::RedLruMap(int _maxSize)
{
    maxSize = _maxSize;
}

template <typename K, typename V>
RedLruMap<K, V>::~RedLruMap()
{

}

template <typename K, typename V>
int RedLruMap<K, V>::Put(const K & k, V & v)
{
    // LruRemove();
    RedLruData<V> * data = new RedLruData<V>();
    data->hot = 0;
    data->t = v;

    mapSet.insert(typename std::map<K, RedLruData<V> *>::value_type(k, data));
    return 0;
}

template <typename K, typename V>
int RedLruMap<K, V>::Get(const K & k, V & v)
{
    typename std::map<K, RedLruData<V> *>::iterator iter;
    iter = mapSet.find(k);
    if(iter != mapSet.end()){
        RedLruData<V> * data = iter->second;
        data->hot++;
        v = data->t;

        return 0;
    }
    return -1;
}

template <typename K, typename V>
int RedLruMap<K, V>::Size()
{
    return mapSet.size();
}

template <typename K, typename V>
int RedLruMap<K, V>::LruRemove()
{
    while(mapSet.size() > maxSize){
        LruRemoveHotless();
    }
    return 0;
}

template <typename K, typename V>
int RedLruMap<K, V>::LruRemoveHotless()
{
    int hot = -1;
    K k;
    typename std::map<K, RedLruData<V> *>::iterator iter;
    for(iter=mapSet.begin(); iter!=mapSet.end(); iter++) {
        if(hot == -1){
            hot = iter->second->hot;
            k = iter->first;
        }
        if(hot > iter->second->hot){
            hot = iter->second->hot;
            k = iter->first;
        }
    }


    iter = mapSet.find(k);
    if(iter != mapSet.end()){
        RedLruData<V> * data = iter->second;

        delete data;

        mapSet.erase(iter);
    }

    return 0;
}

#endif
