#ifndef	RED_MAP_H
#define	RED_MAP_H

#include <map>
#include <mutex>

template <typename K, typename V>
class RedMap
{
public:
    std::mutex mut;
    std::map<K, V> mapSet;
public:
    RedMap();
    ~RedMap();

    int Get(const K & k, V & v);
    int Put(const K & k, V & v);

    int Size();
};

template <typename K, typename V>
RedMap<K, V>::RedMap()
{

}

template <typename K, typename V>
RedMap<K, V>::~RedMap()
{

}

template <typename K, typename V>
int RedMap<K, V>::Get(const K & k, V & v)
{
    typename std::map<K, V>::iterator iter;
    iter = mapSet.find(k);
    if(iter != mapSet.end()){
        v = iter->second;
        return 0;
    }
    return -1;
}

template <typename K, typename V>
int RedMap<K, V>::Put(const K & k, V & v)
{
    mapSet.insert(typename std::map<K, V>::value_type(k, v));
    return 0;
}

template <typename K, typename V>
int RedMap<K, V>::Size()
{
    return mapSet.size();
}



#endif
