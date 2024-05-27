import React from 'react'

export default class EmailStep extends React.Component {
    render() {
        if (this.props.currentStep !== 2) {
            return null;
        } 
        return(
            <div>
              <label>Email</label>
              <input
                name="email"
                type="text"
                placeholder="Введите email"
                value={this.props.email}
                onChange={this.props.handleChange}
                />
            </div>
        );
    }
    }