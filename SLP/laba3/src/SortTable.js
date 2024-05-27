import { Component } from "react";

export class SortTable extends Component {
  constructor(props) {
    super(props);
    this.sorted = { name: true, price: true, stock: true };
    this.state = { array: this.goods };
  }
  goods = [
    { id: "Milk", name: "Milk", price: 0.8, stock: 0 },
    { id: "Butter", name: "Butter", price: 1.3, stock: 13 },
    { id: "Coffee", name: "Coffee", price: 12, stock: 23 },
    { id: "Tea", name: "Tea", price: 13, stock: 2 },
    { id: "Sugar", name: "Sugar", price: 1.2, stock: 4 },
    { id: "Apples", name: "Apples", price: 1, stock: 16 },
    { id: "Cheese", name: "Cheese", price: 10, stock: 9 },
  ];
  styles = {
    td: {
      padding: "10px 20px",
      border: "1px double",
    },
    table: {
      position: "relative",
      right: "13%",
      border: "2px double",
      margin: "100px",
    },
  };
  sort(count) {
    let direction = this.sorted[count] ? 1 : -1,
      goodsCopy = [...this.goods].sort(function (a, b) {
        if (a[count] > b[count]) {
          return direction;
        }
        if (a[count] < b[count]) {
          return direction * -1;
        }
        return 0;
      });
    this.sorted[count] = !this.sorted[count];
    this.setState({ array: goodsCopy });
  }
  table() {
    let stringNumber = 0;
    return this.state.array.map((item) => {
      let stockStyle = {};
      if (+item.stock < 3) stockStyle = { background: "yellow" };
      if (+item.stock === 0) stockStyle = { background: "red" };
      return (
        <tr key={item.id}>
          <td style={this.styles.td}>{++stringNumber}</td>
          <td style={this.styles.td}>{item.name}</td>
          <td style={this.styles.td}>${item.price}</td>
          <td style={Object.assign({}, this.styles.td, stockStyle)}>
            {item.stock}
          </td>
        </tr>
      );
    });
  }
  head = [
    <tr>
      <td style={this.styles.td}>№</td>
      <td style={this.styles.td}>
        <button onClick={() => this.sort("name")}>Name</button>
      </td>
      <td style={this.styles.td}>
        <button onClick={() => this.sort("price")}>Price</button>
      </td>
      <td style={this.styles.td}>
        <button onClick={() => this.sort("inStock")}>Stock</button>
      </td>
    </tr>,
  ];
  render() {
    return (
      <table style={this.styles.table}>
        {this.head}
        {this.table()}
      </table>
    );
  }
}
