package pop_up;

import rappidcart.signup;
import rappidcart.login;

public class unsuccessfull_window extends javax.swing.JFrame {

    Boolean signUp_check = false;
    Boolean login_check = false;
    Boolean month_day_check = false;
    Boolean year_check = false;
    Boolean proceed_check = false;
    Boolean forgotPassword_check = false;
    Boolean retypeNewPass_check = false;
    
    
    public unsuccessfull_window() {
        initComponents();
    }

    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        jPanel1 = new javax.swing.JPanel();
        jPanel2 = new javax.swing.JPanel();
        jPanel3 = new javax.swing.JPanel();
        continue_ = new javax.swing.JButton();
        jPanel4 = new javax.swing.JPanel();
        jLabel1 = new javax.swing.JLabel();
        alert_box_ = new javax.swing.JLabel();
        cross_button_ = new javax.swing.JButton();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);
        setUndecorated(true);

        jPanel2.setBackground(new java.awt.Color(255, 255, 255));

        jPanel3.setBackground(new java.awt.Color(255, 255, 255));

        continue_.setBackground(new java.awt.Color(253, 87, 101));
        continue_.setFont(new java.awt.Font("Segoe UI", 1, 14)); // NOI18N
        continue_.setForeground(new java.awt.Color(255, 255, 255));
        continue_.setText("Continue");
        continue_.setBorder(new javax.swing.border.SoftBevelBorder(javax.swing.border.BevelBorder.RAISED));
        continue_.setBorderPainted(false);
        continue_.setCursor(new java.awt.Cursor(java.awt.Cursor.HAND_CURSOR));
        continue_.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                continue_ActionPerformed(evt);
            }
        });

        javax.swing.GroupLayout jPanel3Layout = new javax.swing.GroupLayout(jPanel3);
        jPanel3.setLayout(jPanel3Layout);
        jPanel3Layout.setHorizontalGroup(
            jPanel3Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addComponent(continue_, javax.swing.GroupLayout.Alignment.TRAILING, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
        );
        jPanel3Layout.setVerticalGroup(
            jPanel3Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addComponent(continue_, javax.swing.GroupLayout.Alignment.TRAILING, javax.swing.GroupLayout.DEFAULT_SIZE, 55, Short.MAX_VALUE)
        );

        jPanel4.setBackground(new java.awt.Color(255, 255, 255));

        jLabel1.setIcon(new javax.swing.ImageIcon(getClass().getResource("/images/unsuccessful_picture.png"))); // NOI18N

        alert_box_.setFont(new java.awt.Font("Segoe UI", 1, 16)); // NOI18N
        alert_box_.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);

        cross_button_.setFont(new java.awt.Font("Segoe UI", 1, 14)); // NOI18N
        cross_button_.setText("X");
        cross_button_.setBorderPainted(false);
        cross_button_.setCursor(new java.awt.Cursor(java.awt.Cursor.HAND_CURSOR));
        cross_button_.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                cross_button_ActionPerformed(evt);
            }
        });

        javax.swing.GroupLayout jPanel4Layout = new javax.swing.GroupLayout(jPanel4);
        jPanel4.setLayout(jPanel4Layout);
        jPanel4Layout.setHorizontalGroup(
            jPanel4Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, jPanel4Layout.createSequentialGroup()
                .addGap(0, 0, Short.MAX_VALUE)
                .addComponent(cross_button_))
            .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, jPanel4Layout.createSequentialGroup()
                .addContainerGap(144, Short.MAX_VALUE)
                .addComponent(jLabel1)
                .addGap(138, 138, 138))
            .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, jPanel4Layout.createSequentialGroup()
                .addContainerGap()
                .addComponent(alert_box_, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                .addContainerGap())
        );
        jPanel4Layout.setVerticalGroup(
            jPanel4Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel4Layout.createSequentialGroup()
                .addComponent(cross_button_)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(jLabel1, javax.swing.GroupLayout.DEFAULT_SIZE, 66, Short.MAX_VALUE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(alert_box_, javax.swing.GroupLayout.PREFERRED_SIZE, 37, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(36, 36, 36))
        );

        javax.swing.GroupLayout jPanel2Layout = new javax.swing.GroupLayout(jPanel2);
        jPanel2.setLayout(jPanel2Layout);
        jPanel2Layout.setHorizontalGroup(
            jPanel2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addComponent(jPanel3, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
            .addComponent(jPanel4, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
        );
        jPanel2Layout.setVerticalGroup(
            jPanel2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, jPanel2Layout.createSequentialGroup()
                .addComponent(jPanel4, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(jPanel3, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
        );

        javax.swing.GroupLayout jPanel1Layout = new javax.swing.GroupLayout(jPanel1);
        jPanel1.setLayout(jPanel1Layout);
        jPanel1Layout.setHorizontalGroup(
            jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGap(0, 335, Short.MAX_VALUE)
            .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                .addGroup(jPanel1Layout.createSequentialGroup()
                    .addGap(0, 0, Short.MAX_VALUE)
                    .addComponent(jPanel2, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addGap(0, 0, Short.MAX_VALUE)))
        );
        jPanel1Layout.setVerticalGroup(
            jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGap(0, 239, Short.MAX_VALUE)
            .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                .addGroup(jPanel1Layout.createSequentialGroup()
                    .addGap(0, 0, Short.MAX_VALUE)
                    .addComponent(jPanel2, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addGap(0, 0, Short.MAX_VALUE)))
        );

        getContentPane().add(jPanel1, java.awt.BorderLayout.CENTER);

        pack();
        setLocationRelativeTo(null);
    }// </editor-fold>//GEN-END:initComponents

    private void continue_ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_continue_ActionPerformed
        if(signUp_check == true){
            signUp_check = false;

            alert_box_.setText("");
            dispose();
            
            new login().setVisible(true);
        }
        
        if(login_check == true){
            login_check = false;

            alert_box_.setText("");
            dispose();
        }
        
        if(forgotPassword_check == true){
            forgotPassword_check = false;

            alert_box_.setText("");
            dispose();
        }
        
        if(month_day_check == true){
            month_day_check = false;

            alert_box_.setText("");
            dispose();
        } if(year_check == true){
            year_check = false;

            alert_box_.setText("");
            dispose();
        }
        
        if(proceed_check == true){
            proceed_check = false;

            alert_box_.setText("");
            dispose();
        }
        
        if(retypeNewPass_check == true){
            retypeNewPass_check = false;

            alert_box_.setText("");
            dispose();
        }
    }//GEN-LAST:event_continue_ActionPerformed
 
    private void cross_button_ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_cross_button_ActionPerformed
        if(signUp_check == true){
            signUp_check = false;

            alert_box_.setText("");
            dispose();
            
            new login().setVisible(true);
        }
        
        if(login_check == true){
            login_check = false;

            alert_box_.setText("");
            dispose();
        }
        
        if(forgotPassword_check == true){
            forgotPassword_check = false;

            alert_box_.setText("");
            dispose();
        }
        
        if(month_day_check == true){
            month_day_check = false;

            alert_box_.setText("");
            dispose();
        } if(year_check == true){
            year_check = false;

            alert_box_.setText("");
            dispose();
        }
        
        if(proceed_check == true){
            proceed_check = false;

            alert_box_.setText("");
            dispose();
        }
        
        if(retypeNewPass_check == true){
            retypeNewPass_check = false;

            alert_box_.setText("");
            dispose();
        }
    }//GEN-LAST:event_cross_button_ActionPerformed

    
    //called from newPassword_reset & control the pop up successful_window for retypeNewPass
    public void control_unsuccessful_popUp_window_retypeNewPass(){
        retypeNewPass_check = true;
        alert_box_.setText(alert_box_.getText() + "Password did not match");
        setVisible(true);
    }
    
    
    //called from signup class & control the pop up successful_window for proceed
    public void control_unsuccessful_popUp_window_proceed(){
        proceed_check = true;
        alert_box_.setText(alert_box_.getText() + "Please fill all information");
        setVisible(true);
    }
    
    
    //called from signup class & control the pop up successful_window for year
    public void control_unsuccessful_popUp_window_year(){
        year_check = true;
        alert_box_.setText(alert_box_.getText() + "Enter Day and Month First");
        setVisible(true);
    }
    
    
    //called from signup class & control the pop up successful_window for month+day
    public void control_unsuccessful_popUp_window_month_day(){
        month_day_check = true;
        alert_box_.setText(alert_box_.getText() + "Enter Valid Number");
        setVisible(true);
    }
    
    
    //called from forgotpassword & control the pop up successful_window for forgotPassword
    public void control_Unsuccessful_popUp_window_forgotPassword(){
        forgotPassword_check = true;
        alert_box_.setText(alert_box_.getText() + "Invalid username or bithdate");
        setVisible(true);
    }
    
    //called from signup class(Cancel button) & control the pop up successful_window for login
    public void control_Unsuccessful_popUp_window_login(){
        login_check = true;
        alert_box_.setText(alert_box_.getText() + "Wrong Username or Password");
        setVisible(true);
    }
    
    
    //called from signup class(Cancel button) & control the pop up successful_window for signUp
    //Also wwork for newPassword_reset (calcel button).
    public void control_Unsuccessful_popUp_window_signUp_forgotPassword(){
        signUp_check = true;
        alert_box_.setText(alert_box_.getText() + "Cancelation Successful");
        setVisible(true);
    }


    
    
//    public static void main(String args[]) {
//
//        java.awt.EventQueue.invokeLater(new Runnable() {
//            public void run() {
//                new unsuccessfull_window().setVisible(true);
//            }
//        });
//    }
    
    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JLabel alert_box_;
    private javax.swing.JButton continue_;
    private javax.swing.JButton cross_button_;
    private javax.swing.JLabel jLabel1;
    private javax.swing.JPanel jPanel1;
    private javax.swing.JPanel jPanel2;
    private javax.swing.JPanel jPanel3;
    private javax.swing.JPanel jPanel4;
    // End of variables declaration//GEN-END:variables
}