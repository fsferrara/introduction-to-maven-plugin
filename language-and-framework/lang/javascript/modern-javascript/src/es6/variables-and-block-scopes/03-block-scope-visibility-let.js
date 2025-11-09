/*
let visibility
*/


// block scope
{
    let block_ans = 42;
}
console.log('[block scope] block_ans = ' + (typeof block_ans === 'undefined' ? 'undefined' : block_ans));


// if block scope
if (true) {
    let if_ans = 42;
}
console.log('[if block scope] if_ans = ' + (typeof if_ans === 'undefined' ? 'undefined' : if_ans));


// for block scope
for (let i=0; i<=5; i++) {
    let for_ans=42;
}
console.log('[for block scope] for_ans = ' + (typeof for_ans === 'undefined' ? 'undefined' : for_ans));
console.log('[for block scope] index i = ' + (typeof i === 'undefined' ? 'undefined' : i));

// function scope
function sum() {
    let fun_ans=42;
}
console.log('[function scope] fun_ans = ' + (typeof fun_ans === 'undefined' ? 'undefined' : fun_ans));
