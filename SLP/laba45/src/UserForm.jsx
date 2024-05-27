import React from 'react'
import UserNameStep from './UserNameStep';
import EmailStep from './EmailStep';
import PasswordStep from './PasswordStep';

export default class UserForm extends React.Component {
  constructor(props) {
    super(props)
    this.state = {
      currentStep: 1,
      username: "",
      email:  "",
      password: "", 
    }
  }

  handleChange = event => {
    const {name, value} = event.target
    this.setState({
      [name]: value
    })    
  }
    
  handleSubmit = event => {
    event.preventDefault()
    const { email, username, password } = this.state;
    alert(`Введенные данные: \nИмя: ${username} \nEmail: ${email} \nПароль: ${password}`)
  }
   
  _next = () => {
    let currentStep = this.state.currentStep
    currentStep = currentStep >= 2? 3: currentStep + 1
    this.setState({
      currentStep: currentStep
    })
  }
     
  _prev = () => {
    let currentStep = this.state.currentStep
    currentStep = currentStep <= 1? 1: currentStep - 1
    this.setState({
      currentStep: currentStep
    })
  }

previousButton() {
  let currentStep = this.state.currentStep;
  if(currentStep !==1){
    return (
      <button type="button" onClick={this._prev}>Назад</button>
    )
  }
  return null;
}

nextButton(){
  let currentStep = this.state.currentStep;
  if(currentStep <3){
    return (
      <button type="button" onClick={this._next}>Вперед</button>        
    )
  }
  return null;
}
 
sendButton(){
  let currentStep = this.state.currentStep;
  if(currentStep === 3){
    return (
        <button>Отправить</button>      
    )
  }
  return null;
}

render() {    
return (
  <div>
  <h1>Форма входа</h1>

  <form onSubmit={this.handleSubmit}>
    <UserNameStep
      currentStep={this.state.currentStep} 
      handleChange={this.handleChange}
      username={this.state.username}
    />
    <EmailStep
      currentStep={this.state.currentStep} 
      handleChange={this.handleChange}
      email={this.state.email}
    />
    <PasswordStep
      currentStep={this.state.currentStep} 
      handleChange={this.handleChange}
      password={this.state.password}
    />
    <p>
    {this.previousButton()}
    {this.nextButton()}
    {this.sendButton()}
    </p>
  </form>
  </div>
);
}
}

