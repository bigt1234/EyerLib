#ifndef	EYER_CORE_STRING_H
#define	EYER_CORE_STRING_H

namespace Eyer {
    class EyerString
    {
    public:
        char * str = nullptr;
        int ClearStr();

    public:
        EyerString();
        EyerString(char str[]);
        EyerString(const EyerString & str);
        ~EyerString();

        bool IsEmpty() const;

        EyerString & operator = (const EyerString & s);
        bool operator == (const EyerString & s);

        EyerString operator + (const EyerString & s);
    };
}

#endif
