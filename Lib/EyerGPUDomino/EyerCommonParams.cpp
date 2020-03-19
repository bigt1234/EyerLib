#include "EyerGPUDomino.hpp"

namespace Eyer {
    EyerCommonParams::EyerCommonParams() {

    }

    EyerCommonParams::~EyerCommonParams() {

    }

    EyerCommonParams::EyerCommonParams(const EyerCommonParams &params) {
        *this = params;
    }

    EyerCommonParams &EyerCommonParams::operator=(const EyerCommonParams &params) {
        return *this;
    }

    int EyerCommonParams::PutFloat(EyerString key, float val)
    {
        // param.insert(std::pair<EyerString, float>(key, val));
        return 0;
    }
}