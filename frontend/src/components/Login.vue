<!--suppress ALL -->
<template>
    <el-tabs v-model="activeName">
        <el-tab-pane label="登录" name="login">
            <el-form ref="form" :model="login" label-width="auto" class="form-width">
                <el-form-item label="邮箱">
                    <el-input prefix-icon="el-icon-user" type="email" v-model="login.email" clearable></el-input>
                </el-form-item>
                <el-form-item label="密码">
                    <el-input prefix-icon="el-icon-lock" v-model="login.password" show-password clearable></el-input>
                </el-form-item>
                <el-form-item>
                    <el-button type="primary" @click="PostLogin" @submit="PostLogin">登录</el-button>
                    <el-button @click="clearAll">取消</el-button>
                </el-form-item>
            </el-form>
        </el-tab-pane>
        <el-tab-pane label="注册" name="registry">
            <el-form ref="form" :model="login" label-width="auto" class="form-width">
                <el-form-item label="邮箱">
                    <el-input prefix-icon="el-icon-user" type="email" v-model="registry.email" clearable></el-input>
                </el-form-item>
                <el-form-item label="姓">
                    <el-input prefix-icon="el-icon-user" v-model="registry.firstname" clearable></el-input>
                </el-form-item>
                <el-form-item label="名">
                    <el-input prefix-icon="el-icon-user" v-model="registry.lastname" clearable></el-input>
                </el-form-item>
                <el-form-item label="密码">
                    <el-input prefix-icon="el-icon-lock" v-model="registry.password" show-password clearable></el-input>
                </el-form-item>
                <el-form-item label="验证密码">
                    <el-input prefix-icon="el-icon-lock" v-model="registry.password_verify" show-password clearable></el-input>
                </el-form-item>
                <el-form-item>
                    <el-button type="primary" @click="PostRegistry" @submit="PostRegistry">注册</el-button>
                    <el-button @click="clearAll">取消</el-button>
                </el-form-item>
            </el-form>
        </el-tab-pane>
    </el-tabs>
</template>

<script>
    export default {
        name: "Login",
        data() {
            return {
                activeName: "login",
                login: {
                    email: "",
                    password: ""
                },
                registry: {
                    email: "",
                    password: "",
                    firstname: "",
                    lastname: "",
                    password_verify: "",
                }
            }
        },
        methods: {
            clearAll() {
                this.login.password = "";
                this.login.username = "";
            },
            PostLogin() {
                this.axios.post("/api/login", {
                    email: this.login.email,
                    password: this.login.password
                }).then(response => {
                    console.log("Login successful")
                }).catch(error => console.log(error))
            },
            PostRegistry() {
                this.axios.post("/api/registry", {
                    email: this.registry.email,
                    password: this.registry.password,
                    firstname: this.registry.firstname,
                    lastname: this.registry.lastname,
                    password_verify: this.registry.password_verify,
                }).then(response => {
                    console.log("Login successful")
                }).catch(error => console.log(error))
            }
        }
    }
</script>

<style scoped>
    .form-width {
        width: 60%;
    }
</style>