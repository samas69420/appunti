echo compiling helloworld 
g++ -c -ffunction-sections helloworld.cpp -o helloworld.o
echo compiling log
g++ -c -ffunction-sections Log.cpp  -o Log.o
echo trying linking
#ld helloworld.o Log.o -lc -lstdc++ -> gives problem for the startup code (_start function etc)
g++ Log.o helloworld.o -o helloworld -Wl,--gc-sections
echo compiling all and linking with Os flag
g++ Log.cpp helloworld.cpp -Os -o helloworld

rm ./helloworld
rm *.o

# NOTE
# -ffunction-sections used for --gc-sections (don't link unused functions)
# Os flag optimizes for size
