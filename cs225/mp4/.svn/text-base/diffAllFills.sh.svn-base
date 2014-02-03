#!/bin/bash
allbmps="
images/gradientColorPickerTest.bmp
images/gridColorPickerTest.bmp
images/solidColorPickerTest.bmp
images/pacManDFS.bmp
images/pacManBFS.bmp
frames"

make all > /dev/null
if [ $? -ne 0 ]
then
	exit -1
fi

rm -rf images
rm -rf frames

./testStackQueue > testStackQueue.out
diff testStackQueue.out soln_testStackQueue.out
./testFills all > testFills.out
diff testFills.out soln_testFills.out

for image in $allbmps
do
	diff -r $image soln_$image | grep -v '\.svn'
done

