/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var filter = function(arr, fn) {
    var nums = [];
    arr.forEach((element,i) => {
        if(fn(element,i)){
            nums.push(element);
        }
    })
    return nums;
};