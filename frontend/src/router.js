import Vue from 'vue'
import Router from 'vue-router'
import Home from './views/Home.vue'

Vue.use(Router);

export default new Router({
    mode: 'history',
    base: process.env.BASE_URL,
    routes: [
        {
            path: '/',
            component: Home
        },
        {
            path: '/exercise',
            // route level code-splitting
            // this generates a separate chunk (about.[hash].js) for this route
            // which is lazy-loaded when the route is visited.
            component: () => import(/* webpackChunkName: "about" */ './views/exercise.vue'),
            children: [
                {
                    path: '',
                    component: () => import('./components/Login.vue')
                }, {
                    path: 'login',
                    component: () => import('./components/Login.vue')
                }, {
                    path: 'data',
                    component: () => import('./components/DataTable.vue')
                }
            ]
        }
    ]
})
