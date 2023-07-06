/**
 * @param {integer} init
 * @return { increment: Function, decrement: Function, reset: Function }
 */
var createCounter = function(init) {
    var x=init;
    const increment=()=>{
        return ++x;
    }
    const decrement=()=>{
        return --x;
    }
    const reset=()=>{
        x=init;
        return init;
    }
    return {increment, decrement, reset};
};

/**
 * const counter = createCounter(5)
 * counter.increment(); // 6
 * counter.reset(); // 5
 * counter.decrement(); // 4
 */