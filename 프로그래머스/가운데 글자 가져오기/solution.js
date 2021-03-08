/* 
문제 설명
단어 s의 가운데 글자를 반환하는 함수, solution을 만들어 보세요. 단어의 길이가 짝수라면 가운데 두글자를 반환하면 됩니다.

재한사항
s는 길이가 1 이상, 100이하인 스트링입니다.
*/

function solution(s) {
    var answer = '';
    if(!(s.length >= 1 && s.length <= 100)) return;
    if(s.length%2 == 0){
        // 짝수
        answer = s.slice((s.length / 2) - 1, (s.length / 2) + 1);
    }
    else{
        // 홀수
        answer = s.split('')[Math.floor(s.length / 2)];
    }
    return answer;
}

/* 
테스트 1 〉	통과 (0.07ms, 30.2MB)
테스트 2 〉	통과 (0.04ms, 30.1MB)
테스트 3 〉	통과 (0.05ms, 30.1MB)
테스트 4 〉	통과 (0.07ms, 30.1MB)
테스트 5 〉	통과 (0.07ms, 30.1MB)
테스트 6 〉	통과 (0.06ms, 30.1MB)
테스트 7 〉	통과 (0.06ms, 30MB)
테스트 8 〉	통과 (0.05ms, 30.1MB)
테스트 9 〉	통과 (0.07ms, 29.9MB)
테스트 10 〉	통과 (0.08ms, 30MB)
테스트 11 〉	통과 (0.07ms, 29.9MB)
테스트 12 〉	통과 (0.08ms, 30.1MB)
테스트 13 〉	통과 (0.07ms, 30.1MB)
테스트 14 〉	통과 (0.07ms, 30.2MB)
테스트 15 〉	통과 (0.07ms, 30.1MB)
테스트 16 〉	통과 (0.06ms, 30.1MB)
*/