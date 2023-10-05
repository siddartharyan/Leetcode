/**
 * @param {string} arriveAlice
 * @param {string} leaveAlice
 * @param {string} arriveBob
 * @param {string} leaveBob
 * @return {number}
 */
var countDaysTogether = function(arriveAlice, leaveAlice, arriveBob, leaveBob) {
    const days = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31];
    let [aliceStartMonth,aliceStartDay] = arriveAlice.split('-').map((k)=>parseInt(k));
    let [aliceEndMonth,aliceEndDay] = leaveAlice.split('-').map((k)=>parseInt(k));
    let [bobStartMonth,bobStartDay] = arriveBob.split('-').map((k)=>parseInt(k));
    let [bobEndMonth,bobEndDay] = leaveBob.split('-').map((k)=>parseInt(k));
    const prefixArray = days;
    prefixArray.unshift(0);
    for(let i=2;i<prefixArray.length;++i){
        prefixArray[i] += prefixArray[i-1];
    }
    let startDayOfYearAlice = prefixArray[aliceStartMonth-1] + aliceStartDay;
    let endDayOfYearAlice = prefixArray[aliceEndMonth-1] + aliceEndDay;
    let startDayofYearBob = prefixArray[bobStartMonth-1] + bobStartDay;
    let endDayofYearBob = prefixArray[bobEndMonth-1] + bobEndDay;
    console.log(startDayOfYearAlice,endDayOfYearAlice,startDayofYearBob,endDayofYearBob)
    let totalDays = Math.min(endDayOfYearAlice,endDayofYearBob) - Math.max(startDayOfYearAlice,startDayofYearBob) + 1;
    return totalDays > 0 ? totalDays : 0; 
};