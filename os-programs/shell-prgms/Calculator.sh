status=1

while [ $status == 1 ]
do
echo "1.Add 2.Subtract 3.Multiply 4.Divide 5.Exit"
echo "Enter option"
read option

case $option in
1) echo "Enter 2 no."
read num1
read num2
result=$(( num1 + num2 ))
echo "Result is $result";;
2) echo "Enter 2 no."
read num1
read num2
result=$(( num1 - num2 ))
echo "Result is $result";;
3) echo "Enter 2 no."
read num1
read num2
result=$(( num1 * num2 ))
echo "Result is $result";;
4) echo "Enter 2 no."
read num1
read num2
result=$(( num1 / num2 ))
echo "Result is $result";;
5) status=0;;
*) echo "Enter appropriate option"
esac

done 
