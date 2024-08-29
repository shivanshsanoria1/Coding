
/* ------------ Test 12 ------------ */
/* const fs = require('fs');

const readableStream = fs.createReadStream(__filename);
readableStream.close();

readableStream.on('close', () => console.log('readableStream 1.0')); // 5
setImmediate(() => console.log('setImmediate 1.0')); // 4
setTimeout(() => console.log('setTimeout 1.0'), 0); // 3
Promise.resolve().then(() => console.log('promise 1.0')); // 2
process.nextTick(() => console.log('nextTick 1.0')); // 1 */

/* ------------ Test 11 ------------ */
/* setImmediate(() => console.log('setImmediate 1.0')); 
setTimeout(() => console.log('setTimeout 1.0'), 0);
for(let i=0; i<10000000; i++) {} // slow down the program to make sure setTimeout(fn,0) runs first */

/* ------------ Test 10 ------------ */
// order of execution cannnot be guranteed
/* setImmediate(() => console.log('setImmediate 1.0')); 
setTimeout(() => console.log('setTimeout 1.0'), 0);  */

/* ------------ Test 9 ------------ */
/* setImmediate(() => console.log('setImmediate 1.0')); // 1
setImmediate(() => {
    console.log('setImmediate 2.0'); // 2
    Promise.resolve().then(() => console.log('promise inside setImmediate 2.0')); // 3
    process.nextTick(() => console.log('nextTick inside setImmediate 2.0')); // 4
});
setImmediate(() => console.log('setImmediate 3.0')); // 5 */

/* ------------ Test 8 ------------ */
/* const fs = require('fs');

setImmediate(() => console.log('setImmediate 1.0')); // 4
fs.readFile(__filename, () => {
    console.log('readFile 1.0'); // 5
    setImmediate(() => console.log('setImmediate inside readFile 1.0')); // 8
    Promise.resolve().then(() => console.log('promise inside readFile 1.0')); // 7
    process.nextTick(() => console.log('nextTick inside readFile 1.0')); // 6
}); 
setTimeout(() => console.log('setTimeout 1.0'), 0); // 3
Promise.resolve().then(() => console.log('promise 1.0')); // 2 
process.nextTick(() => console.log('nextTick 1.0')); // 1 */

/* ------------ Test 8 ------------ */
/* const fs = require('fs');

setImmediate(() => console.log('setImmediate 1.0')); // 4
fs.readFile(__filename, () => {
    console.log('readFile 1.0'); // 5
    setImmediate(() => console.log('setImmediate inside readFile 1.0')); // 6
}); 
setTimeout(() => console.log('setTimeout 1.0'), 0); // 3
Promise.resolve().then(() => console.log('promise 1.0')); // 2 
process.nextTick(() => console.log('nextTick 1.0')); // 1 */

/* ------------ Test 7 ------------ */
/* const fs = require('fs');

setImmediate(() => console.log('setImmediate 1.0')); // 4
fs.readFile(__filename, () => console.log('readFile 1.0')); // 5
setTimeout(() => console.log('setTimeout 1.0'), 0); // 3
Promise.resolve().then(() => console.log('promise 1.0')); // 2 
process.nextTick(() => console.log('nextTick 1.0')); // 1 */

/* ------------ Test 6 ------------ */
/* setTimeout(() => console.log('setTimeout 1.0'), 0); // 9
setTimeout(() => { 
    console.log('setTimeout 2.0'); // 10 
    Promise.resolve().then(() => console.log('promise inside setTimeout 2.0')); // 12
    process.nextTick(() => console.log('nextTick inside setTimeout 2.0')); // 11
}, 0); // 
setTimeout(() => { 
    console.log('setTimeout 3.0'); // 13
    Promise.resolve().then(() => console.log('promise inside setTimeout 3.0')); // 15
    process.nextTick(() => console.log('nextTick inside setTimeout 3.0')); // 14
}, 0);

process.nextTick(() => console.log('nextTick 1.0')); // 1
process.nextTick(() => {
    console.log('nextTick 2.0'); // 2
    process.nextTick(() => console.log('nextTick 2.1')); // 4
});
process.nextTick(() => console.log('nextTick 3.0')); // 3

Promise.resolve().then(() => console.log('promise 1.0')); // 5
Promise.resolve().then(() => {
    console.log('promise 2.0'); // 6
    Promise.resolve().then(() => console.log('promise 2.1')); // 8
}); 
Promise.resolve().then(() => console.log('promise 3.0')); // 7  */

/* ------------ Test 5 ------------ */
/* setTimeout(() => console.log('setTimeout 1.0'), 0); // 9
setTimeout(() => { 
    console.log('setTimeout 2.0'); // 10 
    process.nextTick(() => console.log('nextTick inside setTimeout 2.0')); // 11
}, 0); // 
setTimeout(() => console.log('setTimeout 3.0'), 0); // 12

process.nextTick(() => console.log('nextTick 1.0')); // 1
process.nextTick(() => {
    console.log('nextTick 2.0'); // 2
    process.nextTick(() => console.log('nextTick 2.1')); // 4
});
process.nextTick(() => console.log('nextTick 3.0')); // 3

Promise.resolve().then(() => console.log('promise 1.0')); // 5
Promise.resolve().then(() => {
    console.log('promise 2.0'); // 6
    Promise.resolve().then(() => console.log('promise 2.1')); // 8
}); 
Promise.resolve().then(() => console.log('promise 3.0')); // 7  */

/* ------------ Test 4 ------------ */
/* setTimeout(() => console.log('setTimeout 1.0'), 0); // 9
setTimeout(() => console.log('setTimeout 2.0'), 0); // 10
setTimeout(() => console.log('setTimeout 3.0'), 0); // 11

process.nextTick(() => console.log('nextTick 1.0')); // 1
process.nextTick(() => {
    console.log('nextTick 2.0'); // 2
    process.nextTick(() => console.log('nextTick 2.1')); // 4
});
process.nextTick(() => console.log('nextTick 3.0')); // 3

Promise.resolve().then(() => console.log('promise 1.0')); // 5
Promise.resolve().then(() => {
    console.log('promise 2.0'); // 6
    Promise.resolve().then(() => console.log('promise 2.1')); // 8
}); 
Promise.resolve().then(() => console.log('promise 3.0')); // 7  */

/* ------------ Test 3 ------------ */
/* process.nextTick(() => console.log('nextTick 1.0')); // 1
process.nextTick(() => {
    console.log('nextTick 2.0'); // 2
    process.nextTick(() => console.log('nextTick 2.1')); // 4
});
process.nextTick(() => console.log('nextTick 3.0')); // 3

Promise.resolve().then(() => console.log('promise 1.0')); // 5
Promise.resolve().then(() => {
    console.log('promise 2.0'); // 6
    Promise.resolve().then(() => console.log('promise 2.1')); // 8
}); 
Promise.resolve().then(() => console.log('promise 3.0')); // 7 */

/* ------------ Test 2 ------------ */
/* Promise.resolve().then(() => console.log('promise')); // 2
process.nextTick(() => console.log('nextTick')); // 1 */

/* ------------ Test 1 ------------ */
/* console.log('start'); // 1
process.nextTick(() => console.log('nextTick')); // 3
console.log('end'); // 2 */