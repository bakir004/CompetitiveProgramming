function solution(m, n) {
    const squares = m + n * 4;
    const root = Math.floor(Math.sqrt(squares));
    return root * root
}

console.log(solution(13, 3))