/*
Destructuring an object means to extract some properties out of it.
*/

const circle = {
    label: 'circleX',
    radius: 2,
};

const circleArea = ({radius}) => {
    return (Math.PI * (radius * radius)).toFixed(2);
}

console.log(circleArea(circle));
