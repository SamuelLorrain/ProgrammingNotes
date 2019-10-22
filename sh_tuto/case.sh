while :
do
    read INPUT_STRING
    case $INPUT_STRING in
        hello)
                echo "Hello";;
        bye)
                echo "Bye"
                break
                ;;
        *)      echo "Sorry I dont understand";;
    esac
done


