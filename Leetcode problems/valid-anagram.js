//leetcode problem: Valid Anagram

var isAnagram = function(s, t) {
    
    if(s.length !== t.length) return false;
    let freq = new Array(26).fill(0);
    
    let ch = 'a';
    for(let i = 0; i < s.length; i++){
        freq[s[i].charCodeAt(0) - ch.charCodeAt(0)] += 1;  
    }
    
    for(let i = 0; i < t.length; i++){
        freq[t[i].charCodeAt(0) - ch.charCodeAt(0)] -= 1;  
    }
    
    for(let i = 0; i < 26; i++){
        // console.log(freq[i]);
        if(freq[i] != 0) return false;
    }
    
    return true;
        
};
