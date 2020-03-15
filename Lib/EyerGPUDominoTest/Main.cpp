#include <stdio.h>
#include <gtest/gtest.h>
#include "EyerGPUDomino/EyerGPUDomino.hpp"

TEST(GPUDomino, GPUDomino){
    Eyer::EyerGomino a("a");
    Eyer::EyerGomino b("b");
    Eyer::EyerGomino c("c");
    Eyer::EyerGomino d("d");

    Eyer::EyerGomino gomino("gomino");


    Eyer::EyerGominoPip pip;
    pip << &a;
    pip << &b;
    pip << &c;
    pip << &d;
    pip << &gomino;

    pip.PrintStruct();
}

int main(int argc,char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}