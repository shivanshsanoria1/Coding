function generateRandomString(len = 13){
    const chars = []
    // 0 - 9
    for(let i=0; i<10; i++){
        chars.push(String.fromCharCode(48 + i));
    }
    // A - Z
    for(let i=0; i<26; i++){
        chars.push(String.fromCharCode(65 + i));
    }
    // a - z
    for(let i=0; i<26; i++){
        chars.push(String.fromCharCode(97 + i));
    }
    
    let randStr = ''
    while(len-- > 0){
        const randIdx = Math.floor(Math.random() * chars.length)
        randStr += chars[randIdx]
    }
    
    return randStr
}

for(let i=1; i<=26; i++){
    const id = generateRandomString()
    console.log(i + ' -> ' + id)
}