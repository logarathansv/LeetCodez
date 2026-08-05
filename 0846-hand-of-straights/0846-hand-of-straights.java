class Solution {
    public boolean isNStraightHand(int[] hand, int groupSize) {
        if(hand.length % groupSize != 0) return false;

        Map<Integer, Integer> mp = new HashMap<>();

        for(int i=0;i<hand.length;i++){
            mp.put(hand[i], mp.getOrDefault(hand[i], 0) + 1);
        }
        for(Map.Entry<Integer, Integer> entry : mp.entrySet()){
            int start = entry.getKey();

            while(mp.getOrDefault(start - 1, 0) > 0) start--;
            
            while(mp.getOrDefault(start, 0) > 0){

                for(int i=0;i<groupSize;i++){
                    int curr = start + i;

                    if(mp.getOrDefault(curr, 0) ==0) return false;
                    else mp.put(curr, mp.get(curr) - 1);
                }
            }
            // while(mp.get(entry.getKey()) > 0){
            //     int first = entry.getKey();
            //     // int s = groupSize;
            //     for(int i=0;i<groupSize;i++){
            //         if(mp.getOrDefault(first, 0) > 0)
            //             mp.put(first, mp.get(first)-1);
            //         else return false;
            //         first += 1;
            //         System.out.print(first);
            //     }
            //     System.out.println();
            // }
        }

        return true;
    }
}