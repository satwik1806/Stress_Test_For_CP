g++ -o a A.cpp
g++ -o b B.cpp
g++ -o gen gen.cpp

@ECHO OFF
FOR /L %%G IN (1,1,10000) DO (
    gen %%G > inp.txt
    a < inp.txt > inp1.txt
    b < inp.txt > inp2.txt
    FC /W C:\Users\satwik\Desktop\CP_Clion\files\inp1.txt C:\Users\satwik\Desktop\CP_Clion\files\inp2.txt > NUL && ECHO same output %%G || ECHO found different output && goto :break
)

:break
inp.txt
