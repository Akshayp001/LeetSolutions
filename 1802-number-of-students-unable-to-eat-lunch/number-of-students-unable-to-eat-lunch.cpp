class Solution {
public:
    bool zeroPresent(queue<int> qu){
        while(!qu.empty()){
            if(qu.front()==0){
                return true;
            }else{
                qu.pop();
            }
        }
        return false;
    }

    bool onePresent(queue<int> qu){
            while(!qu.empty()){
            if(qu.front()==1){
                return true;
            }else{
                qu.pop();
            }
        }
        return false;
    }
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> studs;
        stack<int> sandws;
        for(int i=0;i<students.size();i++){
            studs.push(students[i]);
            sandws.push(sandwiches[students.size()-i-1]);
        }
        int count = 0;
        while(!sandws.empty()){
            if(studs.front()==sandws.top()){
                studs.pop();
                sandws.pop();
            }else{
                if(sandws.top() && onePresent(studs)){
                    int temp = studs.front();
                    studs.pop();
                    studs.push(temp);
                }
                else if((!sandws.top()) && zeroPresent(studs)){
                    int temp = studs.front();
                    studs.pop();
                    studs.push(temp);
                }else{
                    while(!studs.empty()){
                        count++;
                        studs.pop();
                    }
                    break;
                }
                
            }
        }
        return count;
    }
};