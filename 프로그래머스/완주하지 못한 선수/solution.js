function solution(participant, completion) {
    var answer = '';
    participant.sort();
    completion.sort();
    for(let i = 0; i <= completion.length + 1; i++){
        if(participant[i] !== completion[i]){
            return participant[i];
        }
    }
    return answer;
}