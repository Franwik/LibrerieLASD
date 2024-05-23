
# Make and Execute exercises

start=3
finish=3
for i in $(seq $start $finish); do
  make -C exercise$i
  exercise$i/main
  result=$?
  output="Test for ex$i terminated with $result error"
  if [ "$result" -ne 1 ]; then
    output+="s"
  fi
  echo $output
  if [ "$result" -ne 0 ]; then
    echo "Test for ex$i failed! Please check the code before pushing again."
    exit 1
  fi
done