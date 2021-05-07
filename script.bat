FOR /L %%G IN (1,1,7) DO (
    @ECHO OFF
    gen %%G > inp.txt
    a < inp.txt > inp1.txt
    b < inp.txt > inp2.txt
    FC /W C:\Users\satwik\Desktop\CP_Clion\files\inp1.txt C:\Users\satwik\Desktop\CP_Clion\files\inp2.txt > NUL && ECHO same output || ECHO found different output && inp.txt
)
