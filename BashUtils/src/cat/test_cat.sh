FUNC_SUCCESS=0
FUNC_FAIL=0
COUNTER=0
DIFF=""

declare -a flags=(
"-b"
"-e"
"-n"
"-s"
"-t"
"-v"
)

declare -a files=(
"s21_cattest1.txt"
"s21_cattest2.txt"
"s21_cattest3.txt"
)

declare -a commline=(
"OPT FILE"
)

declare -a exotic=(
"-b s21_cat.txt -s"
"-benstv nope.txt"
)


function testing()
{
if [ -f "$file" ]; then
    str=$(echo $@ | sed "s/OPT/$options/")
    str=$(echo $str | sed -e "s/FILE/$file/g")
    ./s21_cat $str > s21_cat_testing.log
    cat $str > system_cat_testing.log
    DIFF="$(diff -s s21_cat_testing.log system_cat_testing.log)"
    (( COUNTER++ ))
    if [ "$DIFF" == "Files s21_cat_testing.log and system_cat_testing.log are identical" ]
    then
        (( FUNC_SUCCESS++ ))
        echo "cat $str \033[92mFUNCTIONALITY SUCCESS\033[0m $COUNTER"
    else
        (( FUNC_FAIL++ ))
        echo "cat $str \033[91mFUNCTIONALITY FAIL\033[0m $COUNTER"
    fi
    rm s21_cat_testing.log system_cat_testing.log
else
    echo "cat: $file: No such file or directory"
fi
}



for i in "${exotic[@]}"
do
    testing $i
done

for opt1 in "${flags[@]}"
do
    for opt2 in "${flags[@]}"
    do
        for opt3 in "${flags[@]}"
        do
            for opt4 in "${flags[@]}"
            do
                if [ $opt1 != $opt2 ] && [ $opt1 != $opt3 ] \
                && [ $opt1 != $opt4 ] && [ $opt2 != $opt3 ] \
                && [ $opt2 != $opt4 ] && [ $opt3 != $opt4 ]
                then
                    for file in "${files[@]}"
                    do
                        options="$opt1 $opt2 $opt3 $opt4"
                        testing $commline
                    done
                fi
            done
        done
    done
done

echo "\033[91mFAIL: $FUNC_FAIL\033[0m"
echo "\033[92mSUCCESS: $FUNC_SUCCESS\033[0m"
echo "ALL: $COUNTER"
