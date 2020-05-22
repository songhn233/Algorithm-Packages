let t= readline();
while(t--)
{
  let data = readline();
  let temp = data.split(' ');
  let a = parseInt(temp[0]);
  let b = parseInt(temp[1]);
  let c = parseInt(temp[2]);
  let t = new Date(a,b,c);
  let t1 = new Date(a,4,1);
  let t2 = new Date(a,5,1);
  let mf=t1.getDay();
  if(mf==0) mf=7;
  let tt=15-mf;
  let ff=t2.getDay();
  if(ff==0) ff=7;
  let ttt=22-ff;
  if(b<5||(b==5&&c<tt))
  {
    console.log("Mother's Day: May "+tt+"th, "+a);
  }
  else if(b<6||(b==6&&c<ttt))
  {
    if(ttt==21) console.log("Father's Day: June "+ttt+"st, "+a);
    else console.log("Father's Day: June "+ttt+"th, "+a);
  }
  else
  {
    let p = new Date(a+1,4,1);
    let mm=p.getDay();
    if(mm==0) mm=7;
    mm=15-mm;
    console.log("Mother's Day: May "+mm+"th, "+(a+1));
  }
}
