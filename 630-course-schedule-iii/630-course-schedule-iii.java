class Solution {
    public int scheduleCourse(int[][] courses) {
        Arrays.sort(courses, (c1, c2) -> {
            if(c1[1] == c2[1]){
                return c2[0] - c1[0];
            }
            return c1[1]-c2[1];
        });
        
        PriorityQueue<Integer> pq = new PriorityQueue<>((a, b) -> {
            return courses[b][0] - courses[a][0];
        });
        
        int time = 0;
        
        for(int i = 0; i < courses.length; i++){
            int[] course = courses[i];
            
            if(time + course[0] <= course[1]){
                pq.offer(i);
                time += course[0];
            }
            else{
                if(!pq.isEmpty() && courses[pq.peek()][0] > course[0]){
                    time -= courses[pq.poll()][0];
                    time += course[0];
                    pq.offer(i);
                }
            }
        }
        
        return pq.size();
    }
}