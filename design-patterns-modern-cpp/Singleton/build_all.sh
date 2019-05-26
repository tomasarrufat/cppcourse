for dir in ./*/ ; do 
( 
    cd "$dir" 
    if [ -f "build_all.sh" ]
    then
        ./build_all.sh
    else
        mkdir build && cd build && cmake -GNinja .. && ninja
    fi
); done
