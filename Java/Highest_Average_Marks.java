/**Student with Highest Average Marks**/

import java.util.HashMap;

class HighestAverageMarks {

  static int COLUMNS = 2;

  static String[] getBestStudent (String students[][], int size) {
    String result[] = new String[COLUMNS];
    HashMap<String, HashMap<Integer,Integer>> mp = new HashMap<String, HashMap<Integer, Integer>>();
    int i, total=0, count=0;

    result[1] = "0";

    for(i=0; i<students.length; i++) {
      HashMap<Integer,Integer> temp = null;

      if (!mp.containsKey(students[i][0])) {
        temp = new HashMap<Integer,Integer>();
        total = Integer.valueOf(students[i][1]);
        count = 1;
      } else {
        temp = mp.get(students[i][0]);
        for (HashMap.Entry<Integer, Integer> entry : temp.entrySet()) {
          total = entry.getKey().intValue() + Integer.valueOf(students[i][1]);
          count = entry.getValue().intValue() + 1;
          temp.remove(entry.getKey());
          break;	
        }
      }

      temp.put(new Integer(total), new Integer(count));
      mp.put(students[i][0], temp);

      if (Integer.valueOf(result[1]) <= total/count) {
        result[0] = students[i][0];
        result[1] = String.valueOf(total/count);
      }
    }

    return result;
  }

  public static void main(String args[]) {
    String students[][] = {{"jerry","65"}, {"bob","1"}, {"jerry","23"},{"jerry","23"}, {"jerry","100"},{"Eric","83"}};
    int size = students.length;
    String bestStudent[] = getBestStudent(students, size);
    System.out.println(bestStudent[0] + " - " + bestStudent[1]);
  }
}
