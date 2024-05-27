let container_burger = document.querySelector(".container_burger"); 
let header__nav = document.querySelector(".header__nav"); 
container_burger.addEventListener("click", () => {
  container_burger.classList.toggle("change"); 
  if (!header__nav.classList.contains("active")) {
    header__nav.classList.add("active"); 
    document.body.style.overflow = "hidden"; 
  } else {
    document.body.style.overflow = "visible"; 
    header__nav.classList.remove("active"); 
  }
});

let time = document.querySelector(".time"); 
time_now = new Date(); 
hours = time_now.getHours(); 
minutes = time_now.getMinutes(); 
if (minutes < 10) {
  minutes = "0" + minutes; 
}
if (hours < 10) {
  hours = "0" + hours; 
}
fullTime = `${hours}:${minutes}`; 
time.innerHTML = fullTime; 
setInterval(() => {
  time_now = new Date();
  hours = time_now.getHours();
  minutes = time_now.getMinutes();
  if (minutes < 10) {
    minutes = "0" + minutes;
  }
  if (hours < 10) {
    hours = "0" + hours;
  }
  fullTime = `${hours}:${minutes}`;
  time.innerHTML = fullTime;
}, 1000);

let day = document.querySelector(".day");
let months = [
  "Января",
  "Февраля",
  "Марта",
  "Апреля",
  "Мая",
  "Июня",
  "Июля",
  "Августа",
  "Сентября",
  "Октября",
  "Ноября",
  "Декабря",
]; 
let days = new Date().getDate();
let month = new Date().getMonth();
day.innerHTML = `${days} ${months[month]}`; 
