for dir in ./*/ ; do 
( 
    cd "$dir" 
    if [ -f "clean_all.sh" ]
    then
        ./clean_all.sh
    elif [ -d "build" ]
    then
        rm -rf build
    fi
); done
