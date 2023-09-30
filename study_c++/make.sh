command=$1
g++ -g -w $command.cpp -o $command && ./$command
