import React, { useEffect, useState } from "react";
import ReactDOM from 'react-dom';

class Choose_prof extends React.Component{
constructor(props){
super(props);
this.state={
prof : ""
}
this.targer = "";
}
render(){
return <div>
<select onChange={(e)=>{
this.setState({
prof : e.target.value,
})
}}>
<option value="программист">программист</option>
<option value="инженер">инженер</option>
<option value="доктор">доктор</option>
<option value="космонавт">космонавт</option>
<option value="актер">актер</option>
</select>
<JobMenu value = {this.state.prof}/>
</div>
}
}

class JobMenu extends React.Component{
func(){
switch (this.props.value) {
case "программист":{
return <div>
<a href="https://metanit.com/">https://metanit.com/</a><br/>
<a href="https://timeweb.com/ru/community/articles/luchshie-sayty-dlya..">https://timeweb.com/ru/community/articles/luchshie-sayty-dlya..</a><br/>
<a href="https://ravesli.com/70-besplatnyh-resursov-dlya-izucheniya-pr..">https://ravesli.com/70-besplatnyh-resursov-dlya-izucheniya-pr..</a><br/>
<a href="#">ссылка</a><br/>
<a href="#">ссылка</a><br/>
<a href="#">ссылка</a><br/>
<a href="#">ссылка</a><br/>
</div>
}
case "инженер":{
return <div>
<a href="https://www.proektant.by/">https://www.proektant.by/</a><br/>
<a href="http://saitinpro.ru/">http://saitinpro.ru/</a><br/>
<a href="https://xn----8sbbilafpyxcf8a.xn--p1ai/">https://xn----8sbbilafpyxcf8a.xn--p1ai/</a><br/>
<a href="#">ссылка</a><br/>
<a href="#">ссылка</a><br/>
<a href="#">ссылка</a><br/>
<a href="#">ссылка</a><br/>
</div>
}
case "доктор":{
return <div>
<a href="https://doktora.by/">https://doktora.by/</a><br/>
<a href="https://lubimydoctor.by/">https://lubimydoctor.by/</a><br/>
<a href="https://doctortut.by/">https://doctortut.by/</a><br/>
<a href="#">ссылка</a><br/>
<a href="#">ссылка</a><br/>
<a href="#">ссылка</a><br/>
<a href="#">ссылка</a><br/>
</div>
}
case "космонавт":{
return <div>
<a href="https://www.cosmonavt.su/">https://www.cosmonavt.su/</a><br/>
<a href="https://vk.com/kosmonavtclub">https://vk.com/kosmonavtclub</a><br/>
<a href="https://kosmo-museum.ru/">https://kosmo-museum.ru/</a><br/>
<a href="#">ссылка</a><br/>
<a href="#">ссылка</a><br/>
<a href="#">ссылка</a><br/>
<a href="#">ссылка</a><br/>
</div>
}
case "актер":{
return <div>
<a href="https://www.kino-teatr.ru/kino/db/ros/acter/">https://www.kino-teatr.ru/kino/db/ros/acter/</a>
<a href="https://acter-sochi.ru/">https://acter-sochi.ru/</a><br/>
<a href="https://akter.by/">ссылка</a><br/>
<a href="#">ссылка</a><br/>
<a href="#">ссылка</a><br/>
<a href="#">ссылка</a><br/>
<a href="#">ссылка</a><br/>
</div>
}
}
}
render(){
return(
<p>
{this.func()}
</p>
);
}
}

export default Choose_prof;

import React, { useEffect, useState } from "react";
import ReactDOM from 'react-dom';

class Clock extends React.Component {
constructor(props) {
super(props);
this.state = {
time: new Date()
};
}
// this.props.hour = true;
componentDidMount() {
this.intervalID = setInterval(() => this.tick(), 1000);
}
componentWillUnmount() {
clearInterval(this.intervalID);
}
tick() {
this.setState({
time: new Date(),
});
}
render() {
return <p className="App-clock">The time is {this.state.time.toLocaleString('ru', {timeZone : this.props.time_zone, hour12 : this.props.hour})}.</p>;
}
}

export default Clock;