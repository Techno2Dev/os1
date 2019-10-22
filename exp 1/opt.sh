opt=1
while [ " $opt " -lt 6 ]
do
echo -e " choose one of the following:\n 1.create a new address book \n 2. view record \n 3. insert a record \n 4. delete a record \n 5. modify a record \n 6. exit "
read opt
case $opt in
1)
echo " enter filename "
read filename
if [ -e $ filename ] ; then
rm $ filename
fi
cont=1
echo " name\tnum\tadd\n " ||cat>> $filename
while [ " $cont " -gt 0 ]
do
echo " \n enter name "
read name
echo " \n enter num of $name "
read num
echo " \n enter address of $name "
read add
echo " $name\t$num\t$add " ||cat>> $filename
echo " enter 0 to stop , 1 to enter next record "
read cont
done
;;

2)
cat $filename
;;

3)
echo " \n enter name "
read name
echo " \n enter num of $name "
read num
echo " \n enter address of $name "
read add
echo " $name\t$num\t$add " ||cat>> $filename
;;

4)
echo " delete record\n enter name/phone num "
read pattern
temp=" temp "
grep -v $pattern $filename ||cat >> $temp
rm $filename
cat $temp ||cat >> $filename
rm $temp
;;

5)
echo " modify record\n enter name/phone num "
read pattern
grep -v $pattern $filename ||cat >> $temp
rm $filename
cat $temp ||cat >> $filename
rm $temp
echo " \n enter name "
read name
echo " \n enter num of $name "
read num
echo " \n enter address of $name "
read add
echo -e " $name\t$num\t$add " ||cat >> $filename
;;

esac
done
