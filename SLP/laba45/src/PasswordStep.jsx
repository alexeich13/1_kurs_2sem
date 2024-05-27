import React from 'react'

export default class PasswordStep extends React.Component {
    render() {
      if (this.props.currentStep !== 3) {
        return null
      } 
      return(
        <div>
          <label>Пароль</label>
          <input
            name="password"
            type="password"
            placeholder="Введите пароль"
            value={this.props.password}
            onChange={this.props.handleChange}
            />      
        </div>
      );
    }
    }