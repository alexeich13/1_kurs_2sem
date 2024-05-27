import React from 'react';
import ReactDOM from 'react-dom/client';
import UserForm from './UserForm';
import UserNameStep from './UserNameStep';
import EmailStep from './EmailStep';
import PasswordStep from './PasswordStep';


const root = ReactDOM.createRoot(document.getElementById('root'));
root.render(
  <React.StrictMode>
    <UserForm/>
    <UserNameStep/>
    <EmailStep/>
    <PasswordStep/>
  </React.StrictMode>
);
