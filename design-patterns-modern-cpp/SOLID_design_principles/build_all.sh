for dir in ./*/ ; do ( cd "$dir" && mkdir build && cd build && cmake -GNinja .. && ninja); done
