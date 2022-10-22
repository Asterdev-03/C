echo "Enter a number"
read num
temp=$num
sum=0

while [ $temp != 0 ]
do
digit=$(( temp%10 ))
sum=$(( sum + ( digit*digit*digit )))
temp=$(( temp/10 ))
done

if [ $sum == $num ]
then echo "Armstrong"
else echo "Not Armstrong"
fi
