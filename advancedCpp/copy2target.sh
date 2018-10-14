if [ $# -eq 0 ]
  then
    target=target
else
    target=$1
fi
mkdir $target
for dir in `find -type d -name 'bin'`; do file=`ls $dir`; cp $dir/$file $target; done;
