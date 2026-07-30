class Solution {
    public boolean isPalindrome(String s) {
        if(s == " ") return true;
        StringBuilder newstr = new StringBuilder();

        for(int i=0;i<s.length();i++){
            Character ch = s.charAt(i);
            if(Character.isLetter(ch) || Character.isDigit(ch)) newstr.append(Character.toLowerCase(ch));
        }

        String str = newstr.toString();
        int st = 0, ed = str.length()-1;
        while(st < ed){
            if(str.charAt(st) != str.charAt(ed)) {return false;}
            st++;ed--;
        }

        return true;
    }
}