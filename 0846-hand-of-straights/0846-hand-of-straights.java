class Solution {
    public boolean isNStraightHand(int[] hand, int groupSize) {
        if(hand.length % groupSize != 0) return false;

        Map<Integer, Integer> mp = new TreeMap<>();

        for(int i=0;i<hand.length;i++){
            mp.put(hand[i], mp.getOrDefault(hand[i], 0) + 1);
        }
        for(Map.Entry<Integer, Integer> entry : mp.entrySet()){
            while(mp.get(entry.getKey()) > 0){
                int first = entry.getKey();
                int s = groupSize;
                while(s-- != 0 && mp.containsKey(first)){
                    if(mp.getOrDefault(first, 0) > 0)
                        mp.put(first, mp.get(first)-1);
                    else return false;
                    first += 1;
                    System.out.print(first);
                }
                System.out.println();
                if(s != -1) return false;
            }
        }

        return true;
    }
}