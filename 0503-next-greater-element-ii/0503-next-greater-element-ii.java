class Solution {
    public int[] getArray(int size){
        int[] arr = new int[size];
        for(int i = 0; i < size;i++){
            arr[i] = -1;
        }
        return arr;
    }
    public int[] nextGreaterElements(int[] nums) {
        Stack<Integer> s = new Stack<Integer>();
        int[] answer = getArray(nums.length);
        for(int times = 0; times < 2;times ++){
            for(int i = 0; i < nums.length;i++){
                while(!s.isEmpty() && nums[s.peek()] < nums[i]){
                    answer[s.peek()] = nums[i];
                    s.pop();
                }
                s.push(i);
            }
        }
        return answer;
    }
}