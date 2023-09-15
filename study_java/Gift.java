import java.util.*;

import java.util.Map.Entry;

public class Gift {
    public int getValue(int[] gifts, int n) {
        // write code here
        int[] fill = new int[n];
        //value map times
        Map<Integer, Integer> moneyMapTimes = new HashMap<Integer, Integer>();

        int money;
        for(int i = 0; i < n; i++){
            money = gifts[i];
            if(moneyMapTimes.get(gifts[i]) == null){
                moneyMapTimes.put(gifts[i], 0);
            }else {
                moneyMapTimes.put(gifts[i], moneyMapTimes.get(gifts[i]) + 1);
            }
        }
	System.out.println(moneyMapTimes);
        //sort
        List<Entry<Integer, Integer>> list = new ArrayList<>(moneyMapTimes.entrySet());
	list.sort(Entry.comparingByValue());
	System.out.println(list);
        if(list.get(0).getValue() >= n/2 ){
            return list.get(0).getKey();
        } else {
            return 0;
        }

    }

	public static void main(String[] args){
		int[] a = new int[]{1, 2, 3, 2, 2};
		new Gift().getValue(a, 5);
	}
}
