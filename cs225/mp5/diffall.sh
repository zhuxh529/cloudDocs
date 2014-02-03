#!/bin/bash
allimgs="outHalf.bmp
outCopy.bmp
outRotated.bmp
outPruned.bmp
outEtc.bmp"

make -q
if [ $? -ne 0 ]
then
	make all
	if [ $? -ne 0 ]
	then
		exit -1
	fi
fi

./mp5 > mp5.out
diff mp5.out soln_mp5.out

for image in $allimgs
do
	diff $image soln_$image
done

