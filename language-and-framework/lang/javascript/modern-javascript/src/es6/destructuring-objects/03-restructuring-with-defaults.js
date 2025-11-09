/*
Destructuring an object means to extract some properties out of it.
*/


// {radius}          --> destructuring
// {radius = 2}      --> default value if the destructuring cannot find the selected field
// {radius = 2} = {} --> default value in case of no parameter
const circleArea = ({radius = 2} = {}) => {
    return (Math.PI * (radius * radius)).toFixed(2);
}

console.log(circleArea({radius: 3}));
console.log(circleArea({foo: 'bar'}));
console.log(circleArea());
