import React from "react";
import "./phoneInput.css";

export class PhoneStep extends React.Component {
  state = {
    number: "",
    showTheList: false,
    value: "Беларусь",
    mask: "XXXX (XX) XXX-XX-XX",
    count: 13,
  };
  inputs = [
    {
      value: "Беларусь",
      code: "+375",
      mask: "XXXX (XX) XXX-XX-XX",
      count: 13,
    },
    {
      value: "Украина",
      code: "+380",
      mask: "XXXX (XX) XXX-XX-XX",
      count: 13,
    },
    {
      value: "Россия",
      code: "+7",
      mask: "XX (XXX) XXX-XX-XX",
      count: 12,
    },
    {
      value: "Польша",
      code: "+48",
      mask: "XXX XXX-XXX-XXX",
      count: 12,
    },
    {
      value: "Литва",
      code: "+370",
      mask: "XXXX (XX) XXX-XX-XX",
      count: 13,
    },
    {
      value: "Латвия",
      code: "+371",
      mask: "XXXX XXXX-XXXX",
      count: 12,
    },
  ];
  theList() {
    return (
      <ul>
        {this.inputs.map((item) => {
          return (
            <li
              onClick={() =>
                this.setState({
                  number: item.code,
                  showTheList: false,
                  mask: item.mask,
                  count: item.count,
                })
              }
              key={item.value}
            >
              <label>
                <input type="radio" name="country" value={item.value} />
                {item.value}
                {item.code}
              </label>
            </li>
          );
        })}
      </ul>
    );
  }

  numberField() {
    return (
      <>
        <label>
          <input
            onClick={() =>
              this.setState({ showTheList: !this.state.showTheList })
            }
            id="number"
            type="tel"
            name="myPhone"
            placeholder="+375 (29) 000-00-00"
            value={this.state.number}
            onChange={this.handleNumberChange}
            maxLength={this.state.count}
          />
        </label>
      </>
    );
  }
  handleNumberChange = (e) => {
    this.setState(
      {
        number: e.target.value,
      },
      () => {
        this.inputs.map((item) => {
          if (this.state.number === item.code)
            this.setState({
              value: item.value,
              mask: item.mask,
              count: item.count,
            });
        });
        if (this.state.count === this.state.number.length) {
          let maskArr = this.state.mask.split(""),
            numberArr = this.state.number.split("");
          for (let i = 0, j = 0; i < maskArr.length; i++)
            if (maskArr[i] === "X") {
              maskArr[i] = numberArr[j];
              j++;
            }
          let number = maskArr.join("");
          this.setState({ number: number });
        }
      }
    );
  };
  render() {
    return (
      <>
        {this.numberField()}
        {this.state.showTheList ? this.theList() : null}
      </>
    );
  }
}