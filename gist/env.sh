function _initblk() {
    mkdir -p $1/t/b $1/b/$2
    echo>$1/t/b/_
    echo Owner:Me|tee $1/t/b/Owner:Me
}
function _solveblk() {
    if [ "$DIFF" != "" ]; then diff=$DIFF; else diff=16; fi
    (cd $1/t/b;ls|../../../minedir -q $diff >../idq)
    cat $1/t/b/*>$1/t/s1.data
    cat $1/t/b/*>$1/t/b/.data
    python pycrypto_test.py sign   $1/t/s1.data 
    python pycrypto_test.py verify $1/t/s1.data 
    cp s1.sig $1/t/b/.sig
    (cd $1/t/b/ ; ../../../ripemd160.py *   >../.id);}

function mkchain() {
    if [ "$1" == "-t" ] ; then shift; x=T; fi
    _initblk $1 0
    if [ "$x" == "T" ] ; then tree -as $1 ; fi;}
function mineblk() {
    if [ "$1" == "-t" ] ; then shift; x=T; fi
    dir=$1
    echo Finish:$when|tee $dir/t/b/"Finish:$when"
    _solveblk $dir
    # this next step is optional
    cp $dir/t/.id $dir/t/b/.id.`cat $dir/t/.id`
    blockno=`ls $dir/b | sort -rn | head -1`
    nextno=`expr $blockno + 1`
    ident=`cat $dir/t/idq`
    when=`date`
    mv $dir/t/b $dir/b/$blockno/$ident
    # set up some default files
    _initblk $dir $nextno
    when=`date`
    echo Blk:$nextno|tee $dir/t/b/"Blk:$nextno"
    echo Start:$when|tee $dir/t/b/"Start:$when"
    echo Prv:$ident |tee $dir/t/b/"Prv:$ident"
    if [ "$x" == "T" ] ; then tree -as $1 ; fi;}
