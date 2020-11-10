# Directories
INPUT_DIR=. # contains *.tar.gz file
TEST_CASES_DIR=./testcases/ # contains all public testcases
SRC_DIR=. # contains uncompressed source code

RED='\033[0;31m'
NC='\033[0m'
GREEN='\033[0;32m'

if [ $# -lt 1 ]
then
  echo "usage: ./eval.sh <ROLL NUMBER>"
  exit
fi

# Extract student directory
ROLL_NO=$1
tar -xzf ${INPUT_DIR}/${ROLL_NO}_A1.tar.gz -C $SRC_DIR

cd ${SRC_DIR}/${ROLL_NO}_A1/
rm -f a.out
make > /dev/null
if [ ! -f a.out ]; then
  echo "Make failed!"
  exit
fi

cd - > /dev/null

# Execute testcases
marks=0
echo "Evaluating $ROLL_NO"
echo "-------------------"
 
count=0
for testcase in `ls $TEST_CASES_DIR/*.c`
do
  test_no_c=`echo "$testcase" | sed "s/.*\///"`
  test_no=$(echo "$(cut -d'.' -f1 <<<"$test_no_c")")
  no=$(echo "$(cut -d'_' -f2 <<<"$test_no")")  
  ${SRC_DIR}/${ROLL_NO}_A1/a.out $testcase > output 2>/dev/null
  val=$(diff output ${TEST_CASES_DIR}/output_${no}.txt | wc -l)
  if [ $val -eq 0 ]
  then
    count=$(echo "${count} + 1" | bc -l)
    echo -e "testcase $no: ${GREEN}passed${NC}"
  else
    echo -e "testcase $no: ${RED}failed${NC} ($(diff output ${TEST_CASES_DIR}/output_${no}.txt))"
  fi 
done
marks=$(echo "scale=2; $count / 2.0" | bc -l)
echo "Marks: $marks / 1"
#rm -f output
