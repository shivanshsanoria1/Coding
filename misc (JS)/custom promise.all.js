/*
# custom Promise.all()
# takes an array of promises as argument
# returns a promise which resolves with an array of values resolved by each promise
# throws an error if any of the promise rejects
*/
function customPromiseAll(promises){
    return new Promise((resolve, reject) => {
        const ans = [];
        let promisesLeft = promises.length;
        promises.forEach((promise, index) => {
            Promise.resolve(promise)
            .then((result) => {
                ans[index] = result;
                promisesLeft--;
                if(promisesLeft === 0)
                    resolve(ans);
            })
            .catch((err) => {
                reject(err);
            });
        });
    });
}

// IIFE
(async function(){
    const p1 = new Promise((res, rej) => {
        setTimeout(() => {
            res(10);
        }, 3000);
    });
    const p2 = new Promise((res, rej) => {
        setTimeout(() => {
            res(20);
        }, 2000);
    });
    const p3 = new Promise((res, rej) => {
        setTimeout(() => {
            res(30);
        }, 1000);
    });
    
    try{
        const promises = [p1,p2,p3];

        // using inbuilt Promise.all()
        /* const p = await Promise.all(promises);
        console.log(p); */
        
        // using custom Promise.all()
        const p = await customPromiseAll(promises);
        console.log(p);
    }catch(err){
        console.log(err);
    }
})();