/**
 * @param {number} rowsCount
 * @param {number} colsCount
 * @return {Array<Array<number>>}
 */
Array.prototype.snail = function(r, c) {
    let n = this.length
    let arr = this
    if(r*c !== n) return []
    let ans = []
    for(let i=0;i<r;++i){
        let l = []
        for(let j=0;j<c;++j) l.push(-1)
        ans.push(l)
    }
    let i=0,j=0;
    let f = false;
    for(let k=0;k<n;){
        f = j%2==0
        i = r-1
        if(f) i = 0
        if(f){
            while(i<r){
                ans[i][j]=arr[k];
                ++i;
                ++k;
            } 
        }else{
            while(i>=0){
                ans[i][j]=arr[k]
                --i;
                ++k;
            }
        }
        ++j;
    }
    return ans;
}

/**
 * const arr = [1,2,3,4];
 * arr.snail(1,4); // [[1,2,3,4]]
 */